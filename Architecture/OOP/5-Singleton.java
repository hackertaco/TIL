public class Logger {
    private static final String CONFIG_FILENAME = 'logger-config.txt';
    private static Logger instance;

    private LogLevel logLevel;
    private BufferedWriter outBuffer;

    private Logger(LogLevel logLevel, String outputPath){
        this.logLevel = logLevel;
        try{
            this.outBuffer = new BufferedWriter(new FileWriter(outputPath));
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    public static Logger getInstance(){
        if(instance != null){
            return instance;
        }

        try{
            String classPath = getClassPath();
            Path loggerConfigPath = Paths.get(classPath, CONFIG_FILENAME);

            File configFile = new File(loggerConfigPath.toString());

            LogLevel logLevel = LogLevel.WARNING;
            String outputFilename = "log.txt";

            if(configFile.isFile()){
                List<String> lines = Files.readAllLines(loggerConfigPath, StandardCharsets.UTF_8);

                for(String line: lines){
                    String[] splits = line.split("=");

                    switch(splits[0]){
                        case "loglevel": logLevel = LogLevel.valueOf(splits[1]);
                            break;
                        case "output": outputFilename = splits[1];
                            break;
                    }
                }
            }

            Path path = Paths.get(classPath, outputFilename);
            String pathString = path.toString();
            instance = new Logger(logLevel, pathString);

            return instance;
        }catch(IOException e){
            throw new RuntimeException(e);

        }
    }

    public void deleteInstance(){
        if(this.outBuffer != null) {
            try {
                this.outBuffer.close();
            }catch(IOException e){
                throw new RuntimeException(e);
            }
        }

        if(instance != null){
            instance = null;
        }
    }

    public void logDebug(String message, Object...args){
        writeToFile(LogLevel.DEBUG, message, args);
    }
     public void logInformation(String message, Object...args){
            writeToFile(LogLevel.DEBUG, message, args);
        }
}