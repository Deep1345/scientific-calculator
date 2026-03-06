pipeline {
    agent any

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
    }

    post {
        success {
            echo 'Build and tests passed successfully'
        }
        failure {
            echo 'Build failed'
        }
    }
}
