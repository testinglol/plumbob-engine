
void FUN_004639d2(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x90);
  if (piVar3 != *(int **)(param_1 + 0x94)) {
    do {
      iVar1 = *piVar3;
      for (puVar2 = *(undefined4 **)(iVar1 + 0x1ac); puVar2 != *(undefined4 **)(iVar1 + 0x1b0);
          puVar2 = puVar2 + 1) {
        *puVar2 = DAT_00667478;
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != *(int **)(param_1 + 0x94));
  }
  return;
}

