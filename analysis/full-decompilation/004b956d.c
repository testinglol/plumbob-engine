
void __thiscall FUN_004b956d(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar5 = (undefined1 *)(*(int *)(param_1 + 8) + 2);
    do {
      uVar3 = FUN_0049bd68((uint)CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5),param_3,param_4);
      iVar1 = *(int *)(DAT_006e486c + 0x34);
      if (iVar1 == 1) {
        uVar2 = FUN_0049f1f4(uVar3);
LAB_004b95dc:
        *(undefined2 *)(param_1 + 0x420 + (param_2 * 0x100 + iVar4) * 2) = uVar2;
      }
      else {
        if (iVar1 == 2) {
          uVar2 = FUN_0049f21b(uVar3);
          goto LAB_004b95dc;
        }
        if (iVar1 == 3) {
          uVar2 = FUN_004a4558(uVar3);
          goto LAB_004b95dc;
        }
        if (iVar1 == 4) {
          uVar2 = FUN_004a4531(uVar3);
          goto LAB_004b95dc;
        }
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar4 < *(int *)(param_1 + 0xc));
  }
  return;
}

