
void FUN_00425ab3(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if ((param_1 != 0) && (iVar2 = FUN_0042573e((int)*(short *)(param_1 + 0x5ca)), iVar2 != 0)) {
    uVar3 = FUN_00423e37();
    *(undefined4 *)(iVar2 + 0x18) = uVar3;
    puVar4 = (undefined4 *)FUN_0042385a(uVar3);
    piVar1 = (int *)puVar4[1];
    for (piVar5 = (int *)*puVar4; piVar5 != piVar1; piVar5 = piVar5 + 2) {
      *(undefined2 *)(iVar2 + 0x74 + *piVar5 * 2) = *(undefined2 *)(param_1 + 0x58c + *piVar5 * 2);
    }
  }
  return;
}

