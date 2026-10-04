
void FUN_00620680(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (0 < param_4) {
    puVar3 = (undefined1 *)(param_1 + -1 + param_3);
    do {
      iVar1 = 0;
      puVar2 = puVar3;
      if (0 < param_3) {
        do {
          *(undefined1 *)(param_2 + iVar1) = *puVar2;
          iVar1 = iVar1 + 1;
          puVar2 = puVar2 + -1;
        } while (iVar1 < param_3);
      }
      param_2 = param_2 + param_5;
      puVar3 = puVar3 + param_5;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

