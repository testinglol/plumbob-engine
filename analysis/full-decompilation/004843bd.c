
void FUN_004843bd(int param_1,short param_2)

{
  int iVar1;
  undefined2 uVar2;
  int *piVar3;
  
  if ((-1 < param_2) && (param_2 < 0xd)) {
    piVar3 = &DAT_006c5bd4;
    do {
      uVar2 = __ftol();
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *(undefined2 *)(param_1 + iVar1 * 2) = uVar2;
    } while ((int)piVar3 < 0x6c5be8);
  }
  return;
}

