/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab5;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;

/**
 *
 * @author Jeremy
 */
public class StingRayGUI extends javax.swing.JFrame {
    
    private static int PACKETSIZE = 100;
    private static int PORT = 9876;
    private static int BYTE_LENGTH = 64;
    
    private static InetAddress host;
    private static int receivePort;
    private static DatagramSocket socket;
    private static String sStatusDialog;
    private static Control control;
    
    /**
     * Creates new form StringRayGUI
     */
    public StingRayGUI() {
        initComponents();
        tStatus.setEditable(false);
        this.setVisible(true);
        disableAll();
        bStart.setEnabled(true);
    }
    
    private void disableAll(){
        tDistance.setEnabled(false);
        tAngle.setEnabled(false);
        bMoveForward.setEnabled(false);
        bMoveBackward.setEnabled(false);
        bRotateRight.setEnabled(false);
        bRotateLeft.setEnabled(false);
        bExit.setEnabled(false);
        bTemperature.setEnabled(false);
        bSonar.setEnabled(false);
        bStart.setEnabled(false);
    }
    
    private void enableAll(){
        tDistance.setEnabled(true);
        tAngle.setEnabled(true);
        bMoveForward.setEnabled(true);
        bMoveBackward.setEnabled(true);
        bRotateRight.setEnabled(true);
        bRotateLeft.setEnabled(true);
        bExit.setEnabled(true);
        bTemperature.setEnabled(true);
        bSonar.setEnabled(true);
        bStart.setEnabled(false);
    }
    /**
     * This method is called from within the constructor to initialize the form. WARNING: Do NOT modify this code. The content of this method is always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        bMoveForward = new javax.swing.JButton();
        bMoveBackward = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        tAngle = new javax.swing.JTextField();
        bRotateRight = new javax.swing.JButton();
        bRotateLeft = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        tDistance = new javax.swing.JTextField();
        bTemperature = new javax.swing.JButton();
        bSonar = new javax.swing.JButton();
        bExit = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        tStatus = new javax.swing.JTextArea();
        bStart = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("StingRay"));

        bMoveForward.setText("MoveForward");
        bMoveForward.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bMoveForwardActionPerformed(evt);
            }
        });

        bMoveBackward.setText("MoveBackward");
        bMoveBackward.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bMoveBackwardActionPerformed(evt);
            }
        });

        jLabel1.setText("Rotate Angle");

        tAngle.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                tAngleKeyPressed(evt);
            }
        });

        bRotateRight.setText("Rotate Clockwise");
        bRotateRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bRotateRightActionPerformed(evt);
            }
        });

        bRotateLeft.setText("Rotate Counter-Clockwise");
        bRotateLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bRotateLeftActionPerformed(evt);
            }
        });

        jLabel2.setText("Move Distance");

        tDistance.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                tDistanceKeyPressed(evt);
            }
            public void keyReleased(java.awt.event.KeyEvent evt) {
                tDistanceKeyReleased(evt);
            }
            public void keyTyped(java.awt.event.KeyEvent evt) {
                tDistanceKeyTyped(evt);
            }
        });

        bTemperature.setText("Temperature");
        bTemperature.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bTemperatureActionPerformed(evt);
            }
        });

        bSonar.setText("Distance to Obstacle");
        bSonar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bSonarActionPerformed(evt);
            }
        });

        bExit.setText("Exit");
        bExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bExitActionPerformed(evt);
            }
        });

        tStatus.setColumns(20);
        tStatus.setRows(5);
        jScrollPane2.setViewportView(tStatus);

        bStart.setText("Start");
        bStart.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bStartActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(bRotateRight)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 116, Short.MAX_VALUE)
                .addComponent(bRotateLeft))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(bMoveForward)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(bMoveBackward))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(tAngle))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(tDistance))))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(bTemperature)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(bSonar))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addComponent(bStart)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(bExit))
            .addComponent(jScrollPane2)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(tDistance, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(bMoveForward)
                    .addComponent(bMoveBackward))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(tAngle, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(bRotateRight)
                    .addComponent(bRotateLeft))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(bTemperature)
                    .addComponent(bSonar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 15, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(bExit)
                    .addComponent(bStart)))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void bMoveForwardActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bMoveForwardActionPerformed
        if(tDistance.getText().length() == 0){
            JOptionPane.showMessageDialog(null, "Enter a distance between 1 and 20");
        }else if (Integer.parseInt(tDistance.getText()) < 0 || Integer.parseInt(tDistance.getText()) > 20){
            JOptionPane.showMessageDialog(null, "Enter a distance between 1 and 20");
        }else{
            disableAll();
            control.sendMessage("1");
            displayMessage("Sending Instruction: Move Forward \n");
            displayMessage("Waiting For Acknowledgement: \n");
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    displayMessage(control.waitForMessage());
                    java.awt.EventQueue.invokeLater(new Runnable() {
                        public void run() {
                            control.sendMessage(tDistance.getText());
                            displayMessage("Sending Distance: " + tDistance.getText() + " \n");
                            displayMessage("Waiting For Acknowledgement: \n");
                            java.awt.EventQueue.invokeLater(new Runnable() {
                                public void run() {
                                    displayMessage(control.waitForMessage());
                                    enableAll();
                                }
                            });
                        }
                    });
                }
            });
        }
    }//GEN-LAST:event_bMoveForwardActionPerformed

    
    private void bStartActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bStartActionPerformed
        displayMessage("Waiting for Robot Greeting... \n");
        bStart.setEnabled(false);
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                displayMessage(control.waitForRemoteGreeting());
                enableAll();
            }
        });
    }//GEN-LAST:event_bStartActionPerformed

    private void displayMessage(String message){
        DateFormat df = new SimpleDateFormat("HH:mm:ss");
        Date date = new Date();
        sStatusDialog += "[" + df.format(date) + "]: " + message;
        tStatus.setText(sStatusDialog);        
        tStatus.repaint();
    }
    
    private void bTemperatureActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bTemperatureActionPerformed
        disableAll();
        control.sendMessage("6");
        displayMessage("Sending Message: Get Temperature \n");
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                displayMessage("Temperature Received: " + control.waitForMessage());
                enableAll();
            }
        });
    }//GEN-LAST:event_bTemperatureActionPerformed

    private void bSonarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bSonarActionPerformed
        disableAll();
        control.sendMessage("5");
        displayMessage("Sending Message: Get Distance to Obstacle \n");
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                displayMessage("Distance Recieved: " + control.waitForMessage());
                enableAll();
            }
        });
    }//GEN-LAST:event_bSonarActionPerformed

    private void tDistanceKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_tDistanceKeyTyped

    }//GEN-LAST:event_tDistanceKeyTyped

    private void tDistanceKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_tDistanceKeyReleased

    }//GEN-LAST:event_tDistanceKeyReleased

    private void tDistanceKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_tDistanceKeyPressed
        if(evt.getKeyCode() < 48 || evt.getKeyCode() > 57){
            JOptionPane.showMessageDialog(null, "Please enter only digits ");
            evt.consume();
        }
    }//GEN-LAST:event_tDistanceKeyPressed

    private void bMoveBackwardActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bMoveBackwardActionPerformed
        if(tDistance.getText().length() == 0){
            JOptionPane.showMessageDialog(null, "Enter a distance between 1 and 20");
        }else if (Integer.parseInt(tDistance.getText()) < 0 || Integer.parseInt(tDistance.getText()) > 20){
            JOptionPane.showMessageDialog(null, "Enter a distance between 1 and 20");
        }else{
            disableAll();
            control.sendMessage("2");
            displayMessage("Sending Instruction: Move Backward \n");
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    displayMessage("Waiting For Acknowledgement " + control.waitForMessage());
                    java.awt.EventQueue.invokeLater(new Runnable() {
                        public void run() {
                            control.sendMessage(tDistance.getText());
                            displayMessage("Sending Distance: " + tDistance.getText() + " \n");
                            displayMessage("Waiting For Acknowledgement " + control.waitForMessage());
                            enableAll();
                        }
                    });
                }
            });
        }
    }//GEN-LAST:event_bMoveBackwardActionPerformed

    private void tAngleKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_tAngleKeyPressed
        if(evt.getKeyCode() < 48 || evt.getKeyCode() > 57){
            JOptionPane.showMessageDialog(null, "Please enter only digits ");
            evt.consume();
        }
    }//GEN-LAST:event_tAngleKeyPressed

    private void bRotateRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bRotateRightActionPerformed
        if(tAngle.getText().length() == 0){
            JOptionPane.showMessageDialog(null, "Enter an angle between 1 and 359");
        }else if (Integer.parseInt(tAngle.getText()) < 0 || Integer.parseInt(tAngle.getText()) > 360){
            JOptionPane.showMessageDialog(null, "Enter an angle between 1 and 359");
        }else{
            disableAll();
            control.sendMessage("3");
            displayMessage("Sending Instruction: Rotate Clockwise \n");
            displayMessage("Waiting For Acknowledgement: \n");
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    displayMessage(control.waitForMessage());
                    java.awt.EventQueue.invokeLater(new Runnable() {
                        public void run() {
                            control.sendMessage(tAngle.getText());
                            displayMessage("Sending Angle: " + tAngle.getText() + " \n");
                            displayMessage("Waiting For Acknowledgement: \n");
                            java.awt.EventQueue.invokeLater(new Runnable() {
                                public void run() {
                                    displayMessage(control.waitForMessage());
                                    enableAll();
                                }
                            });
                        }
                    });
                }
            });
        }
    }//GEN-LAST:event_bRotateRightActionPerformed

    private void bRotateLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bRotateLeftActionPerformed
        if(tAngle.getText().length() == 0){
            JOptionPane.showMessageDialog(null, "Enter an angle between 1 and 359");
        }else if (Integer.parseInt(tAngle.getText()) < 0 || Integer.parseInt(tAngle.getText()) > 360){
            JOptionPane.showMessageDialog(null, "Enter an angle between 1 and 359");
        }else{
            disableAll();
            control.sendMessage("4");
            displayMessage("Sending Instruction: Rotate Clockwise \n");
            displayMessage("Waiting For Acknowledgement: \n");
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    displayMessage(control.waitForMessage());
                    java.awt.EventQueue.invokeLater(new Runnable() {
                        public void run() {
                            control.sendMessage(tAngle.getText());
                            displayMessage("Sending Angle: " + tAngle.getText() + " \n");
                            displayMessage("Waiting For Acknowledgement: \n");
                            java.awt.EventQueue.invokeLater(new Runnable() {
                                public void run() {
                                    displayMessage(control.waitForMessage());
                                    enableAll();
                                }
                            });
                        }
                    });
                }
            });
        }
    }//GEN-LAST:event_bRotateLeftActionPerformed

    private void bExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bExitActionPerformed
        disableAll();
        control.sendMessage("7");
        displayMessage("Sending Instruction: Shutdown \n");
        displayMessage("Waiting for Acknowledgement: \n");
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                displayMessage(control.waitForMessage());
                bStart.setEnabled(true);
            }
        });
    }//GEN-LAST:event_bExitActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(StingRayGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(StingRayGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(StingRayGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(StingRayGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                sStatusDialog = "";
                
                control = new Control();
                StingRayGUI srg = new StingRayGUI();
                
            }
        });
    }

    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bExit;
    private javax.swing.JButton bMoveBackward;
    private javax.swing.JButton bMoveForward;
    private javax.swing.JButton bRotateLeft;
    private javax.swing.JButton bRotateRight;
    private javax.swing.JButton bSonar;
    private javax.swing.JButton bStart;
    private javax.swing.JButton bTemperature;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTextField tAngle;
    private javax.swing.JTextField tDistance;
    private javax.swing.JTextArea tStatus;
    // End of variables declaration//GEN-END:variables
}
