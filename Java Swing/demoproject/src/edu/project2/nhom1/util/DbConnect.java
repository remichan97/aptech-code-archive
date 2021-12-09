/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.project2.nhom1.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mirai
 */
public class DbConnect {

    public static Connection open() {
        try {
            return DriverManager.getConnection("jdbc:mysql://localhost:3306/quanlythuvien", "root", "");
        } catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }

    }

    public static void close(Connection con, PreparedStatement pre, ResultSet rs) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException ex) {
                Logger.getLogger(DbConnect.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        if (pre != null) {
            try {
                pre.close();
            } catch (SQLException ex) {
                Logger.getLogger(DbConnect.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException ex) {
                Logger.getLogger(DbConnect.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static void main(String[] args) {
        System.out.println(open());
    }
}
