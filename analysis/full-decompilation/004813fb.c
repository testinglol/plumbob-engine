
void FUN_004813fb(undefined4 param_1,undefined4 param_2,ushort *param_3,int param_4)

{
  undefined1 *puVar1;
  short sVar2;
  undefined4 uVar3;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  if ((*param_3 & 0x7fff) == 2) {
    return;
  }
  FUN_0046f824(local_44,0,0x40);
  local_50[0] = &PTR_FUN_0066651c;
  FUN_00402122(CONCAT22((short)((uint)local_50 >> 0x10),*param_3) & 0xffff7fff,local_50);
  puVar1 = *(undefined1 **)(param_4 + 4);
  *(undefined2 *)(param_4 + 8) = 0;
  *puVar1 = 0;
  sVar2 = FUN_004021ff(CONCAT22((short)((uint)puVar1 >> 0x10),*param_3) & 0xffff7fff);
  if (sVar2 == 0) {
LAB_00481481:
    FUN_0046f917(local_50,0xffffffff);
  }
  else {
    if (sVar2 == 1) {
      uVar3 = 2;
    }
    else if (sVar2 == 2) {
      uVar3 = 1;
    }
    else {
      if (sVar2 != 3) goto LAB_00481481;
      uVar3 = 3;
    }
    FUN_0047fc4a(uVar3,param_4);
  }
  return;
}

