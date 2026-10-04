
void FUN_004ea17e(undefined4 param_1,undefined4 param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  *param_3 = 0;
  *(undefined1 *)(param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 6) = 0;
  *(undefined1 *)((int)param_3 + 5) = 0;
  iVar2 = FUN_004ea2ce(param_1);
  psVar3 = (short *)FUN_004ea2ce(param_2);
  if ((iVar2 != 0) && (psVar3 != (short *)0x0)) {
    iVar5 = (int)*psVar3;
    iVar2 = FUN_00465062(iVar5);
    if (0 < iVar2) {
      iVar4 = FUN_0046518a(iVar5,0);
      *param_3 = iVar4;
      iVar4 = FUN_00465062(iVar5);
      if (iVar4 < 3) {
        param_3[2] = 0;
      }
      else {
        iVar4 = FUN_0046518a(iVar5,2);
        param_3[2] = iVar4;
      }
      iVar4 = FUN_00465062(iVar5);
      if (iVar4 < 1) {
        param_3[3] = 0;
      }
      else {
        iVar4 = FUN_0046518a(iVar5,0);
        param_3[3] = iVar4;
      }
      if (1 < iVar2) {
        iVar4 = FUN_0046518a(iVar5,1);
        if (iVar4 != 0) {
          *(undefined1 *)(param_3 + 1) = 1;
        }
      }
      if (3 < iVar2) {
        iVar2 = FUN_0046518a(iVar5,3);
        if (iVar2 != 0) {
          *(undefined1 *)((int)param_3 + 6) = 1;
        }
      }
      if (DAT_006c4388 <= *param_3) {
        iVar2 = FUN_004ea2ce(param_2);
        psVar3 = (short *)FUN_004ea2ce(param_1);
        if ((iVar2 != 0) && (psVar3 != (short *)0x0)) {
          sVar1 = *psVar3;
          iVar2 = FUN_00465062((int)sVar1);
          if (0 < iVar2) {
            iVar2 = FUN_0046518a((int)sVar1,0);
            if (DAT_006c4388 <= iVar2) {
              *(undefined1 *)((int)param_3 + 5) = 1;
            }
          }
        }
      }
      if (param_3[2] < 0x65) {
        if (param_3[2] < -100) {
          param_3[2] = -100;
        }
      }
      else {
        param_3[2] = 100;
      }
      if (param_3[3] < 0x65) {
        if (param_3[3] < -100) {
          param_3[3] = -100;
        }
      }
      else {
        param_3[3] = 100;
      }
    }
  }
  return;
}

