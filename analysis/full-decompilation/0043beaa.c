
void __thiscall FUN_0043beaa(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **local_22c [3];
  undefined1 local_220 [260];
  undefined **local_11c [3];
  undefined1 local_110 [260];
  int local_c;
  undefined4 *local_8;
  
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  local_c = param_1;
  local_8 = puVar2;
  if (puVar2 != puVar3) {
    do {
      local_8 = local_8 + 1;
      if ((((byte)((int *)*puVar2)[0x2d] & 0xc) == 8) &&
         ((local_8 == puVar3 || (*(int *)*local_8 != *(int *)*puVar2)))) {
        FUN_0046f824(local_220,0,0x104);
        local_22c[0] = &PTR_FUN_006664e8;
        FUN_0046f824(local_110,0,0x104);
        local_11c[0] = &PTR_FUN_006664e8;
        (**(code **)(**(int **)*puVar2 + 0x24))(local_22c);
        FUN_00412122(local_22c,local_11c);
        for (iVar4 = *param_2; iVar4 != param_2[1]; iVar4 = iVar4 + 0x110) {
          iVar1 = FUN_0046f973(local_11c);
          if (iVar1 == 0) {
            param_1 = local_c;
            if (iVar4 != param_2[1]) goto LAB_0043bf96;
            break;
          }
        }
        FUN_004129d9(local_11c);
        param_1 = local_c;
      }
LAB_0043bf96:
      puVar3 = *(undefined4 **)(param_1 + 0x24);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar3);
  }
  return;
}

