
undefined4 FUN_0044adcc(undefined4 param_1,int *param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *param_2;
  sVar2 = FUN_00453181(*(undefined1 *)((int)param_2 + 6),(short)param_2[1],0);
  iVar3 = FUN_00407498((int)sVar2);
  if (iVar3 == 0) {
    param_2 = (int *)0x17;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_00698f30);
  }
  if (*(int *)(iVar3 + 0x11c) == 0) {
LAB_0044ae40:
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_0045741b();
    if (iVar3 != iVar1) {
      FUN_004573f9();
      iVar3 = FUN_0045741b();
      if (iVar3 != iVar1) goto LAB_0044ae40;
    }
    uVar4 = 1;
  }
  return uVar4;
}

