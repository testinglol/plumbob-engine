
int * FUN_005832f7(char *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = _strncmp(param_1,&DAT_006d0428,4);
  if (iVar1 != 0) {
    pcVar3 = param_1;
    FUN_005b8e25(param_1);
    FUN_005b960e(pcVar3);
    uVar4 = 1;
    FUN_005b8e25(param_1,1);
    param_1 = (char *)FUN_005b936f(param_1,uVar4);
  }
  piVar2 = (int *)0x0;
  if ((param_1 != (char *)0x0) && (piVar2 = (int *)FUN_005a9320(0x2424), piVar2 != (int *)0x0)) {
    *piVar2 = (int)param_1;
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar2[3] = 0;
    piVar2[4] = (int)(piVar2 + 0x109);
    piVar2[5] = (int)(piVar2 + 0x109);
    piVar2[6] = 1;
    piVar2[7] = 0;
    piVar2[8] = 0;
    *(undefined1 *)(piVar2 + 9) = 0;
    *(undefined1 *)(piVar2 + 0x89) = 0;
  }
  return piVar2;
}

