
void __thiscall
FUN_0047dd77(int param_1,undefined4 param_2,ushort *param_3,undefined4 param_4,undefined4 param_5)

{
  ushort *puVar1;
  ushort uVar2;
  
  puVar1 = param_3 + 2;
  uVar2 = *param_3 & 0x7fff;
  if (0xff < uVar2) {
LAB_0047e128:
    FUN_0047f9d2(puVar1,*(undefined4 *)(param_1 + 4),param_4,uVar2);
    return;
  }
  if ((*(int *)puVar1 == -1) && (*(int *)(param_3 + 4) == -1)) {
    return;
  }
  switch(*param_3 & 0x7fff) {
  case 0:
    FUN_004806c2(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 1:
    func_0x0048011a(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 2:
    FUN_00480586(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 3:
  case 4:
  case 5:
  case 0x1e:
    FUN_0046fa24(0x28);
    goto code_r0x0047de94;
  case 6:
    func_0x0047ffb3(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 7:
    func_0x00480707(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 8:
    FUN_00480788(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 9:
    func_0x0047eb86(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 10:
    func_0x0047eb3c(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0xb:
    FUN_004807ed(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0xc:
    FUN_00480873(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0xd:
    FUN_0047ee5a(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0xe:
    FUN_004808fc(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0xf:
    func_0x004809b5(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x10:
    FUN_0047ea78(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x11:
    func_0x00480a0b(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x12:
    func_0x00480a6e(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x13:
    FUN_0047e9ee(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x14:
    func_0x00480ae5(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x15:
    FUN_00480b45(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x16:
    FUN_0047edbb(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x17:
    FUN_0047f7f4(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x18:
    FUN_0047f20f(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x19:
    FUN_00480c03(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x1a:
    FUN_0047f402(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x1b:
    FUN_00480d3c(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x1c:
    FUN_00480472(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x1d:
    FUN_0047e94c(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x1f:
    FUN_00480164(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x20:
    func_0x0047e8c8(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x21:
    FUN_00480dd9(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x22:
    func_0x0047e839(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x23:
    func_0x0047e20e(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x24:
    FUN_0047fca8(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x25:
    FUN_0046f847(s__me_with_stack_obj___006c50a0,0xffffffff);
    break;
  default:
    goto LAB_0047e128;
  case 0x29:
    FUN_0047efb2(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x2a:
    FUN_0048032b(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x2b:
    FUN_00480e69(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x2c:
    FUN_0047ebe6(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x2d:
    FUN_0047f70e(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x2e:
    FUN_00480f1c(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x2f:
    func_0x0047f66e(puVar1,*(undefined4 *)(param_1 + 4),param_4,param_5);
    break;
  case 0x30:
    FUN_0047f99a(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x31:
    FUN_0046fa24(0x28);
    FUN_0046f847(&DAT_006c220c,0xffffffff);
code_r0x0047de94:
    FUN_0046fa24(0x29);
    break;
  case 0x32:
    FUN_0048029f(puVar1,*(undefined4 *)(param_1 + 4),param_4);
    break;
  case 0x33:
    FUN_00480fc3(puVar1,*(undefined4 *)(param_1 + 4),param_4);
  }
  return;
}

