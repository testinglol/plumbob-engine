
void __thiscall
FUN_00481494(undefined4 param_1,undefined4 param_2,undefined4 param_3,ushort *param_4,int param_5)

{
  undefined1 *puVar1;
  short sVar2;
  undefined4 uVar3;
  undefined **local_54 [3];
  undefined1 local_48 [64];
  undefined4 local_8;
  
  local_8 = param_1;
  if ((*param_4 & 0x7fff) == 2) goto LAB_0048152c;
  FUN_0046f824(local_48,0,0x40);
  local_54[0] = &PTR_FUN_0066651c;
  FUN_00402122(CONCAT22((short)((uint)local_54 >> 0x10),*param_4) & 0xffff7fff,local_54);
  puVar1 = *(undefined1 **)(param_5 + 4);
  *(undefined2 *)(param_5 + 8) = 0;
  *puVar1 = 0;
  sVar2 = FUN_004021ff(CONCAT22((short)((uint)puVar1 >> 0x10),*param_4) & 0xffff7fff);
  if (sVar2 == 1) {
    uVar3 = 2;
LAB_0048150f:
    FUN_0047fc4a(uVar3,param_5);
  }
  else {
    if (sVar2 == 2) {
      uVar3 = 1;
      goto LAB_0048150f;
    }
    if (sVar2 == 3) {
      uVar3 = 3;
      goto LAB_0048150f;
    }
  }
  FUN_0046f917(local_54,0xffffffff);
  FUN_0046fa24(0x20);
LAB_0048152c:
  FUN_0047dd77(param_2,param_4,param_5,param_3);
  return;
}

