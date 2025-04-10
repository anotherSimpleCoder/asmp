void setBuildStatus(String message, String state) {
  step([
      $class: "GitHubCommitStatusSetter",
      reposSource: [$class: "ManuallyEnteredRepositorySource", url: "https://github.com/anotherSimpleCoder/cuerate"],
      contextSource: [$class: "ManuallyEnteredCommitContextSource", context: "Run Tests"],
      errorHandlers: [[$class: "ChangingBuildStatusErrorHandler", result: "UNSTABLE"]],
      statusResultSource: [ $class: "ConditionalStatusResultSource", results: [[$class: "AnyBuildResult", message: message, state: state]] ]
  ]);
}

pipeline {
    agent {
        docker {
            image 'ghcr.io/anothersimplecoder/cpp_build_linux_x86_64:latest'
            args '-u root:root'
        }
    }

    stages {
        stage('Get vcpkg') {
            steps {
                script {
                    if(!fileExists('./vcpkg')) {
                        sh 'git clone https://github.com/microsoft/vcpkg.git'
                    }
                }

                sh './vcpkg/bootstrap-vcpkg.sh'
            }
        }

        stage('Install dependencies') {
            steps {
                sh './vcpkg/vcpkg install'
            }
        }

        stage('Link vcpkg to CMake and configure') {
            steps {
                sh 'cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake'
            }
        }

        stage('Build') {
            steps {
                sh 'cmake --build build'
            }
        }

        stage('Run tests') {
            steps {
                sh 'cd build'
                sh 'ctest --output-on-failure'
            }
        }

        stage('Set GitHub status') {
            agent any

            steps {
                setBuildStatus("Test complete", "SUCCESS");
            }
        }
    }
}