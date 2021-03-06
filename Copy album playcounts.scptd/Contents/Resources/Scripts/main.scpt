FasdUAS 1.101.10   ��   ��    k             l      ��  ��   5/
"Copy Album Playcounts" for iTunes
written by JD

How to install:
Just copy this file to /Users/yourusername/Library/iTunes/Scripts/. If the folder doesn't exist, create it. Then go to iTunes, and the script should appear in the script menu.

Script to automatically sync play counts for songs of the same name.

That is, it will scan your selection for songs of the same name; if it finds such a pair, it will copy the play count of the song which has one to the play count of the song which doesn't have one.
This can be especially useful if you get a better quality of an album; then to copy your playcounts to the better version simply select both the new and old version of the album and use this script.

Released under the GNU General Public License.

-- Credits follow

Adopted from "New Play Count" for iTunes
written by Doug Adams
dougadams@mac.com

v2.0 mar 12 09
-- erases played count when play count is '0' - iTunes 8.1 or better

v1.1 aug 24 06
-- works with streams (URL tracks)

v1.0 oct 16 03
-- initial release

Get more free AppleScripts and info on writing your own
at Doug's AppleScripts for iTunes
http://www.dougscripts.com/itunes/

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

Get a copy of the GNU General Public License by writing to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

or visit http://www.gnu.org/copyleft/gpl.html

     � 	 	^ 
 " C o p y   A l b u m   P l a y c o u n t s "   f o r   i T u n e s 
 w r i t t e n   b y   J D 
 
 H o w   t o   i n s t a l l : 
 J u s t   c o p y   t h i s   f i l e   t o   / U s e r s / y o u r u s e r n a m e / L i b r a r y / i T u n e s / S c r i p t s / .   I f   t h e   f o l d e r   d o e s n ' t   e x i s t ,   c r e a t e   i t .   T h e n   g o   t o   i T u n e s ,   a n d   t h e   s c r i p t   s h o u l d   a p p e a r   i n   t h e   s c r i p t   m e n u . 
 
 S c r i p t   t o   a u t o m a t i c a l l y   s y n c   p l a y   c o u n t s   f o r   s o n g s   o f   t h e   s a m e   n a m e . 
 
 T h a t   i s ,   i t   w i l l   s c a n   y o u r   s e l e c t i o n   f o r   s o n g s   o f   t h e   s a m e   n a m e ;   i f   i t   f i n d s   s u c h   a   p a i r ,   i t   w i l l   c o p y   t h e   p l a y   c o u n t   o f   t h e   s o n g   w h i c h   h a s   o n e   t o   t h e   p l a y   c o u n t   o f   t h e   s o n g   w h i c h   d o e s n ' t   h a v e   o n e . 
 T h i s   c a n   b e   e s p e c i a l l y   u s e f u l   i f   y o u   g e t   a   b e t t e r   q u a l i t y   o f   a n   a l b u m ;   t h e n   t o   c o p y   y o u r   p l a y c o u n t s   t o   t h e   b e t t e r   v e r s i o n   s i m p l y   s e l e c t   b o t h   t h e   n e w   a n d   o l d   v e r s i o n   o f   t h e   a l b u m   a n d   u s e   t h i s   s c r i p t . 
 
 R e l e a s e d   u n d e r   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e . 
 
 - -   C r e d i t s   f o l l o w 
 
 A d o p t e d   f r o m   " N e w   P l a y   C o u n t "   f o r   i T u n e s 
 w r i t t e n   b y   D o u g   A d a m s 
 d o u g a d a m s @ m a c . c o m 
 
 v 2 . 0   m a r   1 2   0 9 
 - -   e r a s e s   p l a y e d   c o u n t   w h e n   p l a y   c o u n t   i s   ' 0 '   -   i T u n e s   8 . 1   o r   b e t t e r 
 
 v 1 . 1   a u g   2 4   0 6 
 - -   w o r k s   w i t h   s t r e a m s   ( U R L   t r a c k s ) 
 
 v 1 . 0   o c t   1 6   0 3 
 - -   i n i t i a l   r e l e a s e 
 
 G e t   m o r e   f r e e   A p p l e S c r i p t s   a n d   i n f o   o n   w r i t i n g   y o u r   o w n 
 a t   D o u g ' s   A p p l e S c r i p t s   f o r   i T u n e s 
 h t t p : / / w w w . d o u g s c r i p t s . c o m / i t u n e s / 
 
 T h i s   p r o g r a m   i s   f r e e   s o f t w a r e ;   y o u   c a n   r e d i s t r i b u t e   i t   a n d / o r   m o d i f y   i t   u n d e r   t h e   t e r m s   o f   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e   a s   p u b l i s h e d   b y   t h e   F r e e   S o f t w a r e   F o u n d a t i o n ;   e i t h e r   v e r s i o n   2   o f   t h e   L i c e n s e ,   o r   ( a t   y o u r   o p t i o n )   a n y   l a t e r   v e r s i o n . 
 
 T h i s   p r o g r a m   i s   d i s t r i b u t e d   i n   t h e   h o p e   t h a t   i t   w i l l   b e   u s e f u l ,   b u t   W I T H O U T   A N Y   W A R R A N T Y ;   w i t h o u t   e v e n   t h e   i m p l i e d   w a r r a n t y   o f   M E R C H A N T A B I L I T Y   o r   F I T N E S S   F O R   A   P A R T I C U L A R   P U R P O S E .     S e e   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e   f o r   m o r e   d e t a i l s . 
 
 G e t   a   c o p y   o f   t h e   G N U   G e n e r a l   P u b l i c   L i c e n s e   b y   w r i t i n g   t o   t h e   F r e e   S o f t w a r e   F o u n d a t i o n ,   I n c . ,   5 1   F r a n k l i n   S t r e e t ,   F i f t h   F l o o r ,   B o s t o n ,   M A     0 2 1 1 0 - 1 3 0 1 ,   U S A . 
 
 o r   v i s i t   h t t p : / / w w w . g n u . o r g / c o p y l e f t / g p l . h t m l 
 
   
  
 l     ��������  ��  ��        p         ������ 0 thismany  ��        p         ������  0 numberofcopies numberOfCopies��        l    ����  O        Z     ��   >   
    1    ��
�� 
sele  J    	����    k    �       r         1    ��
�� 
sele   o      ���� 0 sel     ! " ! r     # $ # m    ����   $ o      ����  0 numberofcopies numberOfCopies "  % & % X    � '�� ( ' k   ' � ) )  * + * r   ' , , - , n   ' * . / . 1   ( *��
�� 
pcnt / o   ' (���� 0 t   - o      ���� 0 t   +  0�� 0 Z   - � 1 2���� 1 G   - < 3 4 3 =  - 2 5 6 5 n   - 0 7 8 7 1   . 0��
�� 
pcls 8 o   - .���� 0 t   6 m   0 1��
�� 
cFlT 4 =  5 : 9 : 9 n   5 8 ; < ; 1   6 8��
�� 
pcls < o   5 6���� 0 t   : m   8 9��
�� 
cURT 2 Z   ? � = >���� = =  ? D ? @ ? n   ? B A B A 1   @ B��
�� 
pPlC B o   ? @���� 0 t   @ m   B C����   > k   G � C C  D E D r   G J F G F m   G H����   G o      ���� 0 thismany   E  H I H X   K � J�� K J k   [ � L L  M N M r   [ ` O P O n   [ ^ Q R Q 1   \ ^��
�� 
pcnt R o   [ \���� 0 t2   P o      ���� 0 t2   N  S�� S Z   a � T U���� T G   a p V W V =  a f X Y X n   a d Z [ Z 1   b d��
�� 
pcls [ o   a b���� 0 t2   Y m   d e��
�� 
cFlT W =  i n \ ] \ n   i l ^ _ ^ 1   j l��
�� 
pcls _ o   i j���� 0 t2   ] m   l m��
�� 
cURT U Z   s � ` a���� ` F   s � b c b =  s z d e d n   s v f g f 1   t v��
�� 
pnam g o   s t���� 0 t   e n   v y h i h 1   w y��
�� 
pnam i o   v w���� 0 t2   c >  } � j k j o   } ~���� 0 t2   k o   ~ ���� 0 t   a k   � � l l  m n m r   � � o p o n   � � q r q 1   � ���
�� 
pPlC r o   � ����� 0 t2   p o      ���� 0 thismany   n  s t s r   � � u v u [   � � w x w o   � �����  0 numberofcopies numberOfCopies x m   � �����  v o      ����  0 numberofcopies numberOfCopies t  y�� y  S   � ���  ��  ��  ��  ��  ��  �� 0 t2   K o   N O���� 0 sel   I  z { z r   � � | } | l  � � ~���� ~ c   � �  �  o   � ����� 0 thismany   � m   � ���
�� 
long��  ��   } n       � � � 1   � ���
�� 
pPlC � o   � ����� 0 t   {  ��� � Z   � � � ����� � =  � � � � � l  � � ����� � c   � � � � � o   � ����� 0 thismany   � m   � ���
�� 
long��  ��   � m   � �����   � Q   � � � ��� � r   � � � � � m   � ���
�� 
msng � n       � � � 1   � ���
�� 
pPlD � o   � ����� 0 t   � R      ������
�� .ascrerr ****      � ****��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� 0 t   ( o    ���� 0 sel   &  � � � r   � � � � � b   � � � � � l  � � ����� � c   � � � � � b   � � � � � m   � � � � � � �  T r a n s f e r r e d   � o   � �����  0 numberofcopies numberOfCopies � m   � ���
�� 
TEXT��  ��   � m   � � � � � � �    p l a y   c o u n t s . � o      ����  0 wtfapplescript wtfAppleScript �  � � � l  � ��� � ���   � R L won't work without a useless variable, AppleScript is truly a gem of design    � � � � �   w o n ' t   w o r k   w i t h o u t   a   u s e l e s s   v a r i a b l e ,   A p p l e S c r i p t   i s   t r u l y   a   g e m   o f   d e s i g n �  ��� � O  � � � � � I   � ��� ����� 0 message_and_ok   �  ��� � o   � �����  0 wtfapplescript wtfAppleScript��  ��   �  f   � ���  ��    l  � � � � � O  � � � � I   ��� ����� 0 message_and_ok   �  ��� � m   � � � � � � & N o   t r a c k s   s e l e c t e d .��  ��   �  f   � � �   no track selected    � � � � $   n o   t r a c k   s e l e c t e d  m      � ��                                                                                  hook  alis    N  Macintosh HD               ���H+  ��b
iTunes.app                                                     �$[���        ����  	                Applications    ��$      ��r    ��b  %Macintosh HD:Applications: iTunes.app    
 i T u n e s . a p p    M a c i n t o s h   H D  Applications/iTunes.app   / ��  ��  ��     � � � l     ��������  ��  ��   �  ��� � i     � � � I      �� ����� 0 message_and_ok   �  ��� � o      ���� 0 ms  ��  ��   � I    �� � �
�� .sysodlogaskr        TEXT � o     ���� 0 ms   � �� � �
�� 
btns � J     � �  ��� � m     � � � � �  O K��   � �� � �
�� 
dflt � m    ����  � �� ���
�� 
disp � m    	����  ��  ��       �� � � ���   � ������ 0 message_and_ok  
�� .aevtoappnull  �   � **** � �� ����� � ����� 0 message_and_ok  �� �� ���  �  �� 0 ms  ��   � �~�~ 0 ms   � �} ��|�{�z�y
�} 
btns
�| 
dflt
�{ 
disp�z 
�y .sysodlogaskr        TEXT�� ���kv�k�j�  � �x ��w�v � ��u
�x .aevtoappnull  �   � **** � k     � �  �t�t  �w  �v   � �s�r�s 0 t  �r 0 t2   �  ��q�p�o�n�m�l�k�j�i�h�g�f�e�d�c�b�a�`�_ ��^ ��]�\ �
�q 
sele�p 0 sel  �o  0 numberofcopies numberOfCopies
�n 
kocl
�m 
cobj
�l .corecnte****       ****
�k 
pcnt
�j 
pcls
�i 
cFlT
�h 
cURT
�g 
bool
�f 
pPlC�e 0 thismany  
�d 
pnam
�c 
long
�b 
msng
�a 
pPlD�`  �_  
�^ 
TEXT�]  0 wtfapplescript wtfAppleScript�\ 0 message_and_ok  �u�*�,jv �*�,E�OjE�O ��[��l kh  ��,E�O��,� 
 	��,� �& ���,j  �jE�O S�[��l kh ��,E�O��,� 
 	��,� �& (��,��, 	 ���& ��,E�O�kE�OY hY h[OY��O��&��,FO��&j   a �a ,FW X  hY hY hY h[OY�POa �%a &a %E` O) 
*_ k+ UY ) 
*a k+ UUascr  ��ޭ