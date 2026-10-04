
void __thiscall FUN_00442699(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int local_c;
  
  for (local_c = *(int *)(param_1 + 0x30); local_c != 0; local_c = *(int *)(local_c + 0xe0)) {
    if (*(int *)(local_c + 0x110) == 0) {
      *(undefined4 *)(local_c + 0x110) = 1;
      *(undefined1 *)(local_c + 0xfe) = 1;
      FUN_005bc69b(s_Forcing_level_0_object_to_level_1_006c3c24);
    }
    if ((param_2 == 0) || (*(int *)(local_c + 0x110) == param_2)) {
      uVar1 = FUN_00433c6a(local_c + 0xf4,*(undefined4 *)(local_c + 0x110));
      *(undefined2 *)(local_c + 0x84) = uVar1;
      if (*(short *)(*(int *)(local_c + 0x118) + 0x12) == 2) {
        iVar2 = FUN_006359f2(local_c,0,&cXObject::RTTI_Type_Descriptor,
                             &cXPerson::RTTI_Type_Descriptor,0);
        if (iVar2 != 0) {
          FUN_0045e5a9();
        }
      }
    }
  }
  for (local_c = *(int *)(param_1 + 0x30); local_c != 0; local_c = *(int *)(local_c + 0xe0)) {
    if ((param_2 == 0) || (*(int *)(local_c + 0x110) == param_2)) {
      FUN_00422d79(7,0,0);
    }
  }
  return;
}

