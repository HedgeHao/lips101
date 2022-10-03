package project_setup;

import org.openni.OpenNI;
import org.openni.Version;

public class App {
    public static void main(String[] args) {
        OpenNI.initialize();

        Version version = OpenNI.getVersion();

        System.out.println("OpenNI:" + version.getMajor() + "." + version.getMinor());
    }
}
