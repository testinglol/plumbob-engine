
void __thiscall FUN_004449d1(int param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00444845();
  local_8 = *(int *)(param_1 + 0x30);
  do {
    while( true ) {
      if (local_8 == 0) {
        return;
      }
      if (*(short *)(*(int *)(local_8 + 0x118) + 0x14) != 0) break;
      local_24 = *(int *)(local_8 + 0xf4);
      local_20 = *(int *)(local_8 + 0xf8);
      piVar3 = (int *)FUN_00422055((int)*param_2,(int)param_2[1]);
      local_20 = local_20 + piVar3[1];
      local_24 = local_24 + *piVar3;
      cVar2 = FUN_00422665(&local_24);
      if (cVar2 == '\0') {
        FUN_00433ef5(&local_24,*(undefined4 *)(local_8 + 0x110),0);
        local_8 = *(int *)(local_8 + 0xe0);
      }
      else {
        iVar1 = *(int *)(local_8 + 0xe0);
        FUN_0044127f(*(undefined2 *)(local_8 + 0xf0));
        local_8 = iVar1;
      }
    }
    local_10 = local_8;
    local_c = *(int *)(local_8 + 400);
    for (local_14 = *(int *)(local_8 + 0xe0);
        ((local_14 != 0 && (*(short *)(*(int *)(local_14 + 0x118) + 0x14) != 0)) &&
        ((local_c == local_14 || (local_c == *(int *)(local_14 + 400)))));
        local_14 = *(int *)(local_14 + 0xe0)) {
    }
    while( true ) {
      if ((local_8 == 0) || (local_8 == local_14)) goto LAB_00444b30;
      local_1c = *(int *)(local_8 + 0xf4);
      local_18 = *(int *)(local_8 + 0xf8);
      piVar3 = (int *)FUN_00422055((int)*param_2,(int)param_2[1]);
      local_18 = local_18 + piVar3[1];
      local_1c = local_1c + *piVar3;
      cVar2 = FUN_00422665(&local_1c);
      if (cVar2 != '\0') break;
      FUN_00433ef5(&local_1c,*(undefined4 *)(local_8 + 0x110),0);
      local_8 = *(int *)(local_8 + 0xe0);
    }
    FUN_0044127f(*(undefined2 *)(local_8 + 0xf0));
LAB_00444b30:
    local_8 = local_14;
  } while( true );
}

