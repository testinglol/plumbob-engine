
int __thiscall FUN_0057c62d(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  
  piVar1 = *(int **)(param_1 + 0x14);
  bVar2 = false;
  bVar3 = false;
  piVar4 = (int *)*piVar1;
  if (piVar4 != piVar1) {
    do {
      bVar2 = (bool)(bVar2 | piVar4[3] <= param_2);
      bVar3 = (bool)(bVar3 | param_2 <= piVar4[3]);
      if ((bVar2) && (bVar3)) break;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != piVar1);
    if ((bVar2) && (bVar3)) {
      return piVar4[2];
    }
  }
  return 0;
}

