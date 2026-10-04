
void __thiscall FUN_0047c718(int param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 4);
  if (-1 < (int)(uVar1 - 1)) {
    puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
    for (uVar2 = uVar1 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = CONCAT22(param_2,param_2);
      puVar3 = puVar3 + 1;
    }
    for (uVar1 = (uint)((uVar1 & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined2 *)puVar3 = param_2;
      puVar3 = (undefined4 *)((int)puVar3 + 2);
    }
  }
  return;
}

