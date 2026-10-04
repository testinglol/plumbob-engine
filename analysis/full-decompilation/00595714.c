
void __fastcall FUN_00595714(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  piVar1 = param_1 + 2;
  iVar2 = (param_1[3] - *piVar1) / 0xc;
  if (-1 < iVar2 + -1) {
    iVar4 = (iVar2 + -1) * 0xc;
    do {
      if (DAT_006f75ec != (code *)0x0) {
        puVar3 = (undefined4 *)(*piVar1 + iVar4);
        (*DAT_006f75ec)(*param_1,param_1[1],*puVar3,puVar3[1],puVar3[2]);
      }
      FUN_00472be0(iVar4 + *piVar1);
      iVar4 = iVar4 + -0xc;
      *(undefined4 *)(*param_1 + 0x98) = 1;
      *(int *)(*param_1 + 0xac) = *(int *)(*param_1 + 0xac) + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (param_1[1] != 0) {
    FUN_00595552(param_1);
    param_1[1] = 0;
  }
  return;
}

