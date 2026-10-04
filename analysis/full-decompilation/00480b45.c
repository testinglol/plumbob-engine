
void FUN_00480b45(short *param_1,undefined4 *param_2)

{
  undefined2 extraout_var;
  undefined **local_110 [2];
  ushort local_108;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  FUN_0046fa24(0x28);
  FUN_00465b21(local_110,*param_2,CONCAT22(extraout_var,*param_1),CONCAT22(extraout_var,param_1[1]))
  ;
  if (local_108 == 0) {
    FUN_0046fa40((int)*param_1);
    FUN_0046f847(&DAT_006c0c28,0xffffffff);
    FUN_0046fa40((int)param_1[1]);
  }
  else {
    FUN_0046f917(local_110,0x30);
    if (0x30 < local_108) {
      FUN_0046f847(&DAT_006c220c,0xffffffff);
    }
  }
  FUN_0046fa24(0x29);
  return;
}

