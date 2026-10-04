
void __thiscall FUN_0047057a(int param_1,uint param_2,undefined4 param_3,char param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = *(char *)(param_1 + 0x5d);
  if (param_4 != -1) {
    cVar2 = param_4;
  }
  piVar1 = (int *)(param_1 + 0x60);
  if ((*(int *)(param_1 + 100) - *piVar1 >> 2) + 1U < param_2) {
    param_2 = (*(int *)(param_1 + 100) - *piVar1 >> 2) + 1;
  }
  if ((int)param_2 < 1) {
    param_2 = 1;
  }
  FUN_00471697();
  iVar3 = *(int *)(param_1 + 100) - *piVar1 >> 2;
  while ((int)param_2 < iVar3) {
    iVar3 = iVar3 + -1;
    *(undefined4 *)(*piVar1 + iVar3 * 4) = *(undefined4 *)(*piVar1 + -4 + iVar3 * 4);
  }
  *(undefined4 *)(*piVar1 + -4 + param_2 * 4) = 0;
  FUN_004704a5(param_2,param_3,cVar2);
  return;
}

