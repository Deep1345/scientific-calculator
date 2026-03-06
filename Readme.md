# Scientific Calculator DevOps Pipeline

## Overview

This project demonstrates a complete **CI/CD DevOps pipeline** for a **C++ Scientific Calculator** using modern DevOps tools.

The project integrates:

- **Git & GitHub** for version control
- **CMake** for build automation
- **GoogleTest** for unit testing
- **Docker** for containerization
- **Jenkins** for CI/CD automation
- **Ansible** for automated deployment

Whenever code is pushed to GitHub, Jenkins automatically:

1. Builds the project
2. Runs unit tests
3. Builds a Docker image
4. Pushes the image to Docker Hub
5. Deploys the container using Ansible

---

## Project Architecture

```text
Developer Push
      |
      v
   GitHub
      |
      v
 GitHub Webhook
      |
      v
   Jenkins Pipeline
      |
      v
 Build with CMake
      |
      v
 Run Google Tests
      |
      v
 Build Docker Image
      |
      v
 Push Image to Docker Hub
      |
      v
 Deploy Container using Ansible
      |
      v
 Running Scientific Calculator Container
