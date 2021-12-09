/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.project2.nhom1.dao;

import edu.project2.nhom1.model.NhaXuatBan;
import edu.project2.nhom1.util.DbConnect;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mirai
 */
public class NhaXuatBanDAO {

    //•Select: lấy dữ liệu từ ResultSet, tạo đối tượng Java bên trên cho từng row lấy từ ResultSet, đưa vào List. Kết quả trả về của select là List đối tượng kia. Chỉ trong DAO mới thấy code select.
    public List<NhaXuatBan> findAll() {
        List<NhaXuatBan> list = new ArrayList<>();

        Connection con = DbConnect.open();
        PreparedStatement stm = null;
        ResultSet rs = null;

        try {
            stm = con.prepareStatement("select * from nha_xuat_ban where status = 1");
            rs = stm.executeQuery();
            while (rs.next()) {
                NhaXuatBan nsb = new NhaXuatBan();
                nsb.setId(rs.getInt("id"));
                nsb.setTen(rs.getString("ten"));

                list.add(nsb);
            }
        } catch (SQLException ex) {
            System.out.println("Loi: " + ex.getMessage());
        } finally {
            DbConnect.close(con, stm, rs);
        }

        return list;
    }

    public boolean addNew(NhaXuatBan nsb) {
        Connection con = DbConnect.open();
        PreparedStatement stm = null;

        try {
            stm = con.prepareStatement("insert into nha_xuat_ban (ten) values (?)");
            stm.setString(1, nsb.getTen());

            return stm.executeUpdate() > 0;
        } catch (SQLException ex) {
            System.out.println("Loi: " + ex.getMessage());
        } finally {
            DbConnect.close(con, stm, null);
        }
        return false;
    }

    public boolean update(NhaXuatBan nsb) {
        Connection con = DbConnect.open();
        PreparedStatement stm = null;

        try {
            stm = con.prepareStatement("update nha_xuat_ban set ten = ? where id = ?");
            stm.setString(1, nsb.getTen());
            stm.setInt(2, nsb.getId());

            return stm.executeUpdate() > 0;
        } catch (SQLException ex) {
            System.out.println("Loi: " + ex.getMessage());
        } finally {
            DbConnect.close(con, stm, null);
        }
        return false;
    }

    public boolean toggleStatus(int id) {
        Connection con = DbConnect.open();
        PreparedStatement stm = null;

        try {
            stm = con.prepareStatement("update nha_xuat_ban set status = !status where id = ?");
            stm.setInt(1, id);

            return stm.executeUpdate() > 0;
        } catch (SQLException ex) {
            System.out.println("Loi: " + ex.getMessage());
        } finally {
            DbConnect.close(con, stm, null);
        }
        return false;
    }

    public boolean delete(int id) {
        Connection con = DbConnect.open();
        PreparedStatement stm = null;

        try {
            stm = con.prepareStatement("update nha_xuat_ban set status = false where id = ?");
            stm.setInt(1, id);

            return stm.executeUpdate() > 0;
        } catch (SQLException ex) {
            System.out.println("Loi: " + ex.getMessage());
        } finally {
            DbConnect.close(con, stm, null);
        }
        return false;
    }
}
