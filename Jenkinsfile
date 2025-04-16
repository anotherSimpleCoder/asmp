pipeline {
    agent { dockerfile true }

    stages {
        stage('Install dependencies') {
            steps {
                sh '/vcpkg/vcpkg install'
            }
        }

        stage('Connect vcpkg to CMake') {
            steps {
                sh 'cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake'
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
    }
}