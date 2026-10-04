
undefined4 __thiscall FUN_0048e01d(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x3c) == 2) {
    if (*(short *)(*(int *)(param_2 + 0x118) + 0x12) == 2) {
      uVar1 = FUN_0059ddcf();
    }
    else {
      uVar1 = FUN_00457ccc();
    }
  }
  else {
    iVar2 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                        );
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0059ddda();
    }
  }
  return uVar1;
}

