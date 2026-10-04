
int * FUN_00583273(char *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = _strncmp(param_1,&DAT_006d0428,4);
  if (iVar1 != 0) {
    uVar3 = 0;
    FUN_005b8e25(param_1,0);
    param_1 = (char *)FUN_005b936f(param_1,uVar3);
  }
  piVar2 = (int *)0x0;
  if (param_1 != (char *)0x0) {
    iVar1 = *(int *)(param_1 + 0x10);
    FUN_005b8f4a(0);
    piVar2 = (int *)FUN_005a9320(0x2424);
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)param_1;
      piVar2[1] = 0;
      piVar2[2] = iVar1;
      piVar2[3] = 0;
      piVar2[4] = (int)(piVar2 + 0x109);
      piVar2[5] = (int)(piVar2 + 0x109);
      piVar2[6] = 0;
      piVar2[7] = 0;
      piVar2[8] = 0;
      *(undefined1 *)(piVar2 + 9) = 0;
      *(undefined1 *)(piVar2 + 0x89) = 0;
    }
  }
  return piVar2;
}

