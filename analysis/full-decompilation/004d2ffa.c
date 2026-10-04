
void FUN_004d2ffa(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffedc;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x20));
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s__d_02d_02d__02d_02d_02d_jpg_006c7c90,
            (uint)*(ushort *)(unaff_EBP + -0x20),(uint)*(ushort *)(unaff_EBP + -0x1e),
            (uint)*(ushort *)(unaff_EBP + -0x1a),(uint)*(ushort *)(unaff_EBP + -0x18),
            (uint)*(ushort *)(unaff_EBP + -0x16),(uint)*(ushort *)(unaff_EBP + -0x14));
  iVar1 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = (undefined4 *)(**(code **)(**(int **)(iVar1 + 0x3c) + 0x94))();
  if (puVar2 != (undefined4 *)0x0) {
    FUN_004b818c(unaff_EBP + -0x124,puVar2,0,0x5a,1,0);
    (**(code **)*puVar2)(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

