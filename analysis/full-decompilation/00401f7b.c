
void FUN_00401f7b(short *param_1,undefined4 param_2,code *param_3)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  undefined2 extraout_var;
  
  FUN_00473102(param_1);
  if (*param_1 < 0) {
    psVar1 = param_1 + 1;
    FUN_00473102(psVar1);
    FUN_004730c5(param_1 + 4);
    sVar3 = 0;
    if (0 < *psVar1) {
      do {
        psVar2 = param_1 + (sVar3 * 3 + 3) * 2;
        FUN_00473102(psVar2);
        (*param_3)(CONCAT22((short)((uint)psVar2 >> 0x10),*psVar2),param_1 + sVar3 * 6 + 8);
        sVar3 = sVar3 + 1;
      } while (sVar3 < *psVar1);
    }
  }
  else {
    sVar3 = 0;
    if (0 < *param_1) {
      do {
        FUN_00473102(param_1 + sVar3 * 6 + 1);
        (*param_3)(CONCAT22(extraout_var,param_1[sVar3 * 6 + 1]),param_1 + sVar3 * 6 + 3);
        sVar3 = sVar3 + 1;
      } while (sVar3 < *param_1);
    }
  }
  return;
}

