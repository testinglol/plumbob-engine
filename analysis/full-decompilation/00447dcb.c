
void __thiscall FUN_00447dcb(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *local_90;
  int *local_54;
  
  if ((param_2 != 0) && (*(char *)(param_1 + 0x11) != '\0')) {
    if (*(short *)(*(int *)(param_2 + 0x118) + 0x12) == 2) {
      iVar1 = FUN_00587d52();
      iVar2 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
      if (((iVar1 != 0) && (iVar1 != 0)) && (iVar2 == iVar1)) {
        FUN_004d40b6();
      }
    }
    iVar1 = FUN_0048e382();
    if (((iVar1 != 0) && (iVar1 != 0)) && (param_2 == iVar1)) {
      FUN_004d40b6();
    }
    iVar1 = FUN_0045741b();
    if (((iVar1 == 0x2f726fff) || (iVar1 == 0xbaa71c5)) || (iVar1 == -0x16cc8fe0)) {
      FUN_004480d7(param_2);
    }
    if ((*(int *)(param_1 + 0xb0) != *(int *)(param_1 + 0xb4)) &&
       (*(short *)(*(int *)(param_2 + 0x118) + 0x12) == 2)) {
      iVar1 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
      for (local_54 = *(int **)(param_1 + 0xb0);
          (local_54 != *(int **)(param_1 + 0xb4) && (*local_54 != iVar1)); local_54 = local_54 + 1)
      {
      }
      if (local_54 != *(int **)(param_1 + 0xb4)) {
        FUN_004486a3(local_54);
      }
    }
    if ((*(int *)(param_1 + 0xbc) != *(int *)(param_1 + 0xc0)) &&
       (*(short *)(*(int *)(param_2 + 0x118) + 0x12) == 2)) {
      iVar1 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
      for (local_90 = *(int **)(param_1 + 0xbc);
          (local_90 != *(int **)(param_1 + 0xc0) && (*local_90 != iVar1)); local_90 = local_90 + 1)
      {
      }
      if (local_90 != *(int **)(param_1 + 0xc0)) {
        FUN_004486a3(local_90);
      }
    }
  }
  return;
}

