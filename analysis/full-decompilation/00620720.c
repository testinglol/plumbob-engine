
void FUN_00620720(int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (0 < param_3) {
    puVar1 = (undefined4 *)((param_3 + -1) * param_4 + param_1);
    do {
      puVar3 = puVar1;
      puVar4 = param_2;
      for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      for (uVar2 = param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      puVar1 = (undefined4 *)((int)puVar1 - param_4);
      param_2 = (undefined4 *)((int)param_2 + param_4);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

