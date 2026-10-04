
void __fastcall FUN_005d7901(int *param_1)

{
  char cVar1;
  char unaff_retaddr;
  
  if (param_1[0x3b] != 0) {
    cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x3b]);
    if (cVar1 != '\0') {
      if (unaff_retaddr == '\0') {
        (**(code **)(*(int *)param_1[0x3b] + 0x98))();
        FUN_005f436c(&DAT_006de560,0,1);
        if (param_1[0x3d] != 0) {
          FUN_00436e16();
        }
      }
      else {
        (**(code **)(*(int *)param_1[0x3b] + 0x94))();
        (**(code **)(*(int *)param_1[0x3b] + 0x44))();
        FUN_00436e16();
        FUN_005ddfdc(1);
      }
    }
  }
  return;
}

