
int __thiscall FUN_005dd429(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*(char *)(param_1 + 0x3c) == '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 1;
  }
  piVar1 = *(int **)(param_1 + 0x38);
  piVar3 = (int *)*piVar1;
  iVar2 = 0;
  if (piVar3 != piVar1) {
    do {
      iVar2 = piVar3[2];
      if ((param_3 << 0x10 | param_2 & 0xffff) == *(uint *)(piVar3[2] + 0x2c)) break;
      piVar3 = (int *)*piVar3;
      iVar2 = 0;
    } while (piVar3 != piVar1);
  }
  *(undefined1 *)(param_1 + 0x3c) = 0;
  return iVar2;
}

