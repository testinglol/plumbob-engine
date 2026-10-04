
void FUN_004258ed(int param_1)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar1 = (undefined2 *)FUN_004257ba(*(undefined4 *)(param_1 + 0x11c));
  if (puVar1 == (undefined2 *)0x0) {
    puVar1 = (undefined2 *)FUN_004257ef(*(undefined4 *)(param_1 + 0x11c),0xffffffff);
    *(undefined2 *)(param_1 + 0x5ca) = *puVar1;
  }
  else {
    *(undefined2 *)(param_1 + 0x5ca) = *puVar1;
    if (*(int *)(puVar1 + 0xc) != 0) {
      puVar2 = (undefined4 *)FUN_0042385a(*(int *)(puVar1 + 0xc));
      for (piVar3 = (int *)*puVar2; piVar3 != (int *)puVar2[1]; piVar3 = piVar3 + 2) {
        if (piVar3[1] <= *(int *)(puVar1 + 0xc)) {
          *(undefined2 *)(param_1 + 0x58c + *piVar3 * 2) = puVar1[*piVar3 + 0x3a];
        }
      }
    }
    *(undefined2 *)(param_1 + 0x606) = puVar1[0x77];
  }
  return;
}

