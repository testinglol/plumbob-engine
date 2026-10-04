
void __fastcall FUN_004824b8(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_00483432();
  iVar2 = FUN_006359f2(*(undefined4 *)(param_1 + 0x4c),0,&cXObject::RTTI_Type_Descriptor,
                       &cXPerson::RTTI_Type_Descriptor,0);
  if (iVar2 != 0) {
    iVar3 = FUN_004670a4(*(undefined2 *)(iVar2 + 0x84));
    if (iVar3 != 0) {
      iVar3 = FUN_004681ec();
      if (0xfa < iVar3) {
        *(undefined4 *)(param_1 + 0x98) = 8;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x4c);
  uVar1 = *(undefined2 *)(iVar3 + 0x4c);
  if (iVar2 != 0) {
    iVar3 = CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(param_1 + 0x94));
    *(undefined2 *)(iVar2 + 0x61e) = *(undefined2 *)(param_1 + 0x94);
  }
  FUN_00483572(CONCAT31((int3)((uint)iVar3 >> 8),*(short *)(iVar2 + 0x60e) < 2));
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x61e) = 0;
  }
  *(undefined2 *)(*(int *)(param_1 + 0x4c) + 0x4c) = uVar1;
  return;
}

