
void __fastcall FUN_00604a27(int *param_1)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  tagMSG local_34;
  int *local_8;
  
  uVar1 = (**(code **)*param_1)(0,&cITSApp::RTTI_Type_Descriptor,&cTSApp::RTTI_Type_Descriptor,0);
  local_8 = (int *)FUN_006359f2(uVar1);
  (**(code **)(*param_1 + 0x18))();
LAB_00604a5d:
  do {
    while( true ) {
      BVar2 = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
      if (BVar2 != 0) break;
      (**(code **)(*local_8 + 0x24))(0);
      (**(code **)(*param_1 + 0x3c))();
    }
    if (local_34.message == 0x12) {
      if (param_1[0x6b] < 1) {
        DAT_006fe8b8 = local_34.wParam;
        return;
      }
      param_1[0x6b] = param_1[0x6b] + -1;
    }
  } while ((DAT_006c9f92 != '\0') && (local_34.message == 0x3e4));
  uVar1 = FUN_005d51f5(s_FW__DispatchMessage_006d91c8,0);
  FUN_004b406a(uVar1);
  if (local_8 != (int *)0x0) goto code_r0x00604ab6;
  goto LAB_00604ac3;
code_r0x00604ab6:
  iVar3 = (**(code **)(*local_8 + 0x24))(&local_34);
  if (iVar3 == 0) {
LAB_00604ac3:
    TranslateMessage(&local_34);
    DispatchMessageA(&local_34);
  }
  goto LAB_00604a5d;
}

