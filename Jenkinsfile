pipeline {
    agent any
    environment {
        IMAGE_NAME = 'deep20180/scientific-calculator'
    }
    stages {
        stage('Clean Workspace Build Folder') {
            steps {
                sh 'rm -rf build'
            }
        }

        stage('Configure Project') {
            steps {
                sh 'mkdir -p build'
                sh 'cd build && cmake ..'
            }
        }

        stage('Build Project') {
            steps {
                sh 'cd build && cmake --build .'
            }
        }

        stage('Run Tests') {
            steps {
                sh 'cd build && ctest --output-on-failure'
            }
        }

        stage('Build Docker Image') {
            steps {
                sh 'docker build -t $IMAGE_NAME:latest .'
            }
        }

        stage('Push Docker Image to Docker Hub') {
            steps {
                withCredentials([usernamePassword(
                    credentialsId: 'dockerhub-creds',
                    usernameVariable: 'DOCKER_USER',
                    passwordVariable: 'DOCKER_PASS'
                )]) {
                    sh '''
                        echo "$DOCKER_PASS" | docker login -u "$DOCKER_USER" --password-stdin
                        docker push $IMAGE_NAME:latest
                        docker logout
                    '''
                }
            }
        }
    }

    post {
        success {
            echo 'Build, test, and Docker push completed successfully.'
        }
        failure {
            echo 'Pipeline failed.'
        }
    }
}
