
void __fastcall FUN_004741c1(int param_1)

{
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  FUN_004704a5(1,s_param_0_006c4d1c,0xffffffff);
  FUN_004704a5(2,s_param_1_006c4d14,0xffffffff);
  FUN_004704a5(3,s_param_2_006c4d0c,0xffffffff);
  FUN_004704a5(4,s_param_3_006c4d04,0xffffffff);
  uStack_8 = CONCAT13(1,(undefined3)uStack_8);
  FUN_004744ca(*(undefined4 *)(param_1 + 0x1f0),4,(int)&uStack_8 + 3);
  *(undefined1 *)(param_1 + 7) = 1;
  *(undefined1 *)(param_1 + 6) = 1;
  return;
}

