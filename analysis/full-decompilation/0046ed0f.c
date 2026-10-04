
undefined4 __thiscall FUN_0046ed0f(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = FUN_00635845(*(undefined4 *)(param_2 + 4),&DAT_006c0a78);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    puVar3 = (undefined4 *)*param_1;
    if (puVar3 != (undefined4 *)param_1[1]) {
      do {
        for (piVar4 = (int *)*puVar3; piVar4 != (int *)puVar3[1]; piVar4 = piVar4 + 1) {
          if (*piVar4 == 0) {
            FUN_006357d8(iVar1,&DAT_006c4a1c);
          }
          else {
            FUN_006357d8(iVar1,&DAT_006c12b4,*piVar4);
          }
        }
        FUN_006357d8(iVar1,&DAT_006c08dc);
        puVar3 = puVar3 + 3;
      } while (puVar3 != (undefined4 *)param_1[1]);
    }
    FUN_0063558d(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

