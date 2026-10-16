FROM eclipse-temurin:21-jre
WORKDIR /app
COPY target/api.jar api.jar
# La JVM usa como máximo el 75 % de la memoria del contenedor
ENV JAVA_TOOL_OPTIONS="-XX:MaxRAMPercentage=75"
EXPOSE 8080
ENTRYPOINT ["java", "-jar", "api.jar"]
