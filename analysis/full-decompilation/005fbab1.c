
bool __thiscall FUN_005fbab1(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  short local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined4 local_c;
  undefined1 uStack_8;
  
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  FUN_005b8e25(param_2,0);
  iVar3 = FUN_005b936f(param_2,uVar4);
  *(int *)(param_1 + 0x44) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  else {
    FUN_005b8f4a(0);
    iVar3 = FUN_005b8e6a((int *)(param_1 + 4),0x14);
    if (iVar3 == 0x14) {
      if ((((*(int *)(param_1 + 0xc) == 0x45564157) && (*(int *)(param_1 + 4) == 0x46464952)) &&
          (0xf < *(uint *)(param_1 + 8))) && (FUN_005b8e6a(&local_1c,0x10), local_1c == 1)) {
        *(undefined2 *)(param_1 + 0x3c) = 0;
        *(undefined2 *)(param_1 + 0x2e) = local_1a;
        *(undefined4 *)(param_1 + 0x30) = local_18;
        *(undefined4 *)(param_1 + 0x34) = local_14;
        *(undefined2 *)(param_1 + 0x38) = local_10;
        bVar1 = false;
        *(undefined2 *)(param_1 + 0x2c) = 1;
        *(undefined2 *)(param_1 + 0x3a) = local_e;
        local_c = DAT_006d8240;
        uStack_8 = DAT_006d8244;
        do {
          iVar3 = FUN_005b8e6a((int)&local_c + 3,1);
          if (iVar3 != 1) goto LAB_005fbbd4;
          if ((((char)local_c == 'd') && (local_c._1_1_ == 'a')) &&
             ((local_c._2_1_ == 't' && (local_c._3_1_ == 'a')))) {
            bVar1 = true;
          }
          uVar2 = (uint)local_c >> 8;
          local_c = CONCAT22(CONCAT11(local_c._3_1_,local_c._3_1_),(short)uVar2);
        } while (!bVar1);
        *(undefined4 *)(param_1 + 0x18) = 0x61746164;
        FUN_005b8e6a(param_1 + 0x1c,4);
      }
      else {
LAB_005fbbd4:
        *(undefined4 *)(param_1 + 0x40) = 3;
      }
      return *(int *)(param_1 + 0x40) == 0;
    }
  }
  return false;
}

