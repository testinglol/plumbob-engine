
void FUN_0043fde8(int param_1,int *param_2)

{
  int iVar1;
  undefined4 extraout_var;
  int local_8;
  
  local_8 = *param_2;
  FUN_0043fd68(param_1,&local_8);
  if (*(int *)(param_1 + 0xc) == 0) {
    if (local_8 == 0) {
      *param_2 = 0;
    }
    else {
      iVar1 = FUN_006359f2(local_8,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0,extraout_var);
      *param_2 = iVar1;
    }
  }
  return;
}

