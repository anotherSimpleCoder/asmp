pipeline {
    agent { dockerfile true }

    stages {
        stage('Install dependencies') {
            steps {
                script {
                    if(!fileExists('/vcpkg')) {
                        sh 'git clone https://github.com/microsoft/vcpkg.git'
                    }

                    sh './vcpkg/bootstrap-vcpkg.sh'
                    sh './vcpkg/vcpkg install'
                }
            }
        }

        stage('Connect vcpkg to CMake') {
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
                dir('build') {
                    sh 'ctest --output-on-failure'
                }
            }
        }
    }
}