
void FUN_005c55c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    puVar1 = param_3 + 5;
    puVar2 = param_1 + 5;
    do {
      if (puVar1 != (undefined4 *)0x14) {
        *param_3 = *param_1;
        puVar1[-4] = puVar2[-4];
        puVar1[-3] = puVar2[-3];
        puVar1[-2] = puVar2[-2];
        puVar1[-1] = puVar2[-1];
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1[3] = puVar2[3];
        puVar1[4] = puVar2[4];
        puVar1[5] = puVar2[5];
        puVar1[6] = puVar2[6];
        puVar1[7] = puVar2[7];
        puVar1[8] = puVar2[8];
        puVar1[9] = puVar2[9];
        puVar1[10] = puVar2[10];
        puVar1[0xb] = puVar2[0xb];
        puVar1[0xc] = puVar2[0xc];
      }
      param_1 = param_1 + 0x12;
      puVar2 = puVar2 + 0x12;
      param_3 = param_3 + 0x12;
      puVar1 = puVar1 + 0x12;
    } while (param_1 != param_2);
  }
  return;
}

