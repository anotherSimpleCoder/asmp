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
            dockerfile true
            args '-u root:root'
        }
    }

    stages {
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