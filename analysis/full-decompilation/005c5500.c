
undefined4 * FUN_005c5500(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = ((int)param_2 - param_1) / 0x48;
  if (0 < iVar3) {
    puVar1 = param_2 + 5;
    puVar2 = param_3 + 5;
    do {
      param_2 = param_2 + -0x12;
      param_3 = param_3 + -0x12;
      if (param_3 != param_2) {
        *param_3 = *param_2;
        puVar2[-0x16] = puVar1[-0x16];
        puVar2[-0x15] = puVar1[-0x15];
        puVar2[-0x14] = puVar1[-0x14];
        puVar2[-0x13] = puVar1[-0x13];
        puVar2[-0x12] = puVar1[-0x12];
        puVar2[-0x11] = puVar1[-0x11];
        puVar2[-0x10] = puVar1[-0x10];
        puVar2[-0xf] = puVar1[-0xf];
        puVar2[-0xe] = puVar1[-0xe];
        puVar2[-0xd] = puVar1[-0xd];
        puVar2[-0xc] = puVar1[-0xc];
        puVar2[-0xb] = puVar1[-0xb];
        puVar2[-10] = puVar1[-10];
        puVar2[-9] = puVar1[-9];
        puVar2[-8] = puVar1[-8];
        puVar2[-7] = puVar1[-7];
        puVar2[-6] = puVar1[-6];
      }
      iVar3 = iVar3 + -1;
      puVar1 = puVar1 + -0x12;
      puVar2 = puVar2 + -0x12;
    } while (iVar3 != 0);
    return param_3;
  }
  return param_3;
}

