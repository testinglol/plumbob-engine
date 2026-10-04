
void __thiscall FUN_00411e6e(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)*param_2;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_00411de1(puVar1 + 1);
    piVar3 = (int *)(*(int *)(param_1 + 4) + iVar2 * 4);
    piVar4 = (int *)*piVar3;
    if (piVar4 == puVar1) {
      *piVar3 = *piVar4;
LAB_00411eb1:
      FUN_0040189d(piVar4,0x38);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
    else {
      piVar3 = piVar4;
      for (piVar4 = (undefined4 *)*piVar4; piVar4 != (undefined4 *)0x0;
          piVar4 = (undefined4 *)*piVar4) {
        if (piVar4 == puVar1) {
          *piVar3 = *piVar4;
          goto LAB_00411eb1;
        }
        piVar3 = piVar4;
      }
    }
  }
  return;
}

