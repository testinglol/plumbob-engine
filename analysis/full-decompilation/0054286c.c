
void __thiscall FUN_0054286c(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = param_2;
  iVar2 = param_2[1];
  iVar4 = *param_2;
  iVar3 = param_2[4];
  if (*(char *)(param_1 + 0x388) == '\0') {
    iVar5 = param_2[2];
    param_2 = (int *)iVar2;
  }
  else {
    if (param_2[3] % param_2[5] == 0) {
      iVar4 = iVar4 - param_2[8];
      iVar2 = iVar2 + 1;
    }
    param_2 = (int *)iVar2;
    if (iVar4 < 1) {
      param_2 = (int *)piVar1[7];
      iVar4 = piVar1[6];
      iVar3 = -0xff;
      iVar2 = _rand();
      piVar1[2] = iVar2 % 3;
    }
    if (iVar4 < 0x65) {
      if (iVar4 < 0x1e) {
        iVar3 = iVar3 + -3;
      }
    }
    else {
      iVar3 = iVar3 + 2;
    }
    if (iVar3 < -0xfe) {
      iVar3 = -0xff;
    }
    if (-0x6f < iVar3) {
      iVar3 = -0x6e;
    }
    piVar1[3] = piVar1[3] + 1;
    iVar5 = piVar1[2];
    piVar1[4] = iVar3;
    piVar1[1] = (int)param_2;
    *piVar1 = iVar4;
  }
  FUN_00542a49(iVar4,param_2,iVar5,iVar3);
  return;
}

