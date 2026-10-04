
void FUN_00616220(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_2 + 0x24)) {
    puVar2 = (undefined1 *)(param_1 + 2);
    puVar1 = (undefined1 *)(param_2 + 0x2a);
    do {
      puVar1[1] = puVar2[-2];
      *puVar1 = puVar2[-1];
      puVar1[-1] = *puVar2;
      puVar1[-2] = puVar2[1];
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 4;
      puVar2 = puVar2 + 0xc;
    } while (iVar3 < *(int *)(param_2 + 0x24));
  }
  return;
}

