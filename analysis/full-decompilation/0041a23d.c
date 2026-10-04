
int FUN_0041a23d(int *param_1,code *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_50;
  int local_4c;
  
  piVar1 = param_1;
  if (param_1[3] == 0) {
    iVar2 = FUN_0041a545(&local_50,*param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    param_1 = (int *)(local_4c + -0x4c);
    if ((((int)param_1 < 0) || (0x40000000 < (int)param_1)) || (local_50 != param_3)) {
      return -1;
    }
    iVar2 = FUN_0041ffd9(param_1);
    piVar1[3] = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_004131a0(*piVar1 + 0x4c);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_00420048(piVar1[3]);
      if (iVar2 != 0) {
        iVar3 = FUN_00413178(iVar2,&param_1);
        if (iVar3 != 0) {
          FUN_00420028(piVar1[3]);
          piVar1[3] = 0;
          return iVar3;
        }
        if (((~(*(byte *)((int)piVar1 + 10) >> 4) & 1) != 0) && (param_2 != (code *)0x0)) {
          (*param_2)(iVar2,param_1);
          *(byte *)(piVar1 + 2) = *(byte *)(piVar1 + 2) | 0x10;
        }
        FUN_0042004f(piVar1[3]);
        goto LAB_0041a30f;
      }
    }
    iVar2 = FUN_00633a1e();
  }
  else {
LAB_0041a30f:
    iVar2 = 0;
  }
  return iVar2;
}

