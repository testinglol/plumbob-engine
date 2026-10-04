
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b9471(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar3 = (undefined2 *)(param_1 + 0x420);
    puVar5 = (undefined1 *)(*(int *)(param_1 + 8) + 2);
    do {
      iVar1 = *(int *)(DAT_006e486c + 0x34);
      if (iVar1 == 1) {
        uVar2 = FUN_0049f1f4((uint)CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5));
LAB_004b9500:
        *puVar3 = uVar2;
      }
      else {
        if (iVar1 == 2) {
          uVar2 = FUN_0049f21b((uint)CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5));
          goto LAB_004b9500;
        }
        if (iVar1 == 3) {
          uVar2 = FUN_004a4558((uint)CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5));
          goto LAB_004b9500;
        }
        if (iVar1 == 4) {
          uVar2 = FUN_004a4531((uint)CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5));
          goto LAB_004b9500;
        }
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar4 < *(int *)(param_1 + 0xc));
  }
  FUN_004b956d(1,0x3f800000,_DAT_006f0118);
  FUN_004b95fd(2,_DAT_00668814);
  FUN_004b95fd(3,_DAT_00667444);
  FUN_004b978e(*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x1c) = DAT_006e5490;
  return;
}

