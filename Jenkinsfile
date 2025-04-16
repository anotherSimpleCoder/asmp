pipeline {
    agent { dockerfile true }

    stages {
        stage('Build') {
            steps {
                sh 'cmake --version'
                sh 'ls'
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