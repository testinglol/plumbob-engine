
void FUN_004d309b(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffedc;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x20));
  DVar2 = timeGetTime();
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_ScreenCap__d_02d_02d__02d_02d__d_006c7cac,
            (uint)*(ushort *)(unaff_EBP + -0x20),(uint)*(ushort *)(unaff_EBP + -0x1e),
            (uint)*(ushort *)(unaff_EBP + -0x1a),(uint)*(ushort *)(unaff_EBP + -0x18),
            (uint)*(ushort *)(unaff_EBP + -0x16),DVar2);
  uVar1 = *(undefined4 *)(DAT_006e486c + 0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b818c(unaff_EBP + -0x124,uVar1,0,100,1,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

