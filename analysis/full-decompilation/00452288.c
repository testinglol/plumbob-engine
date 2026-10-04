
void FUN_00452288(undefined4 param_1,ushort *param_2)

{
  ushort *puVar1;
  
  puVar1 = param_2 + 2;
  switch(*param_2 & 0x7fff) {
  case 0:
    func_0x00451c87(param_1,puVar1);
    break;
  case 1:
    func_0x0044f7e6(param_1,puVar1);
    break;
  case 2:
    FUN_00452c85(puVar1);
    break;
  default:
    param_1 = 5;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_00698f30);
  case 4:
    func_0x00451e1a(param_1,puVar1);
    break;
  case 5:
    func_0x00454470();
    break;
  case 7:
    func_0x00451d3f(param_1,puVar1);
    break;
  case 8:
    FUN_00451eab(param_1,puVar1);
    break;
  case 9:
    FUN_0044d9af(param_1,puVar1);
    break;
  case 10:
    func_0x0044d946(param_1,puVar1);
    break;
  case 0xb:
    func_0x00451f67(param_1,puVar1);
    break;
  case 0xc:
    func_0x00452043(param_1,puVar1);
    break;
  case 0xd:
    FUN_0044cd6b(param_1,puVar1);
    break;
  case 0xe:
    FUN_0044f2ff(param_1,puVar1);
    break;
  case 0xf:
    FUN_00451e74(param_1,puVar1);
    break;
  case 0x10:
    func_0x0044b408(param_1,puVar1);
    break;
  case 0x12:
    FUN_00451baa(param_1,puVar1);
    break;
  case 0x13:
    FUN_0044ae48(param_1,puVar1);
    break;
  case 0x14:
    func_0x0044f6c1(param_1,puVar1);
    break;
  case 0x15:
    FUN_00451af7(param_1,puVar1);
    break;
  case 0x17:
    FUN_00452862(param_1,puVar1);
    break;
  case 0x18:
    func_0x0044d5d3(param_1,puVar1);
    break;
  case 0x19:
    func_0x0044eb1e(param_1,puVar1);
    break;
  case 0x1a:
    func_0x0044d1bc(param_1,puVar1);
    break;
  case 0x1c:
    FUN_0044ba66(param_1,puVar1);
    break;
  case 0x1f:
    func_0x0044ebc0(param_1,puVar1);
    break;
  case 0x20:
    FUN_0044adcc(param_1,puVar1);
    break;
  case 0x21:
    FUN_0044d0b7(param_1,puVar1);
    break;
  case 0x22:
    FUN_0044ad3f(param_1,puVar1);
    break;
  case 0x23:
    FUN_0044aae6(param_1,puVar1);
    break;
  case 0x24:
    func_0x00451592(param_1,puVar1);
    break;
  case 0x29:
    FUN_0044b764(param_1,puVar1);
    break;
  case 0x2a:
    FUN_0044e108(param_1,puVar1);
    break;
  case 0x2b:
    func_0x0044e9aa(param_1,puVar1);
    break;
  case 0x2e:
    FUN_004549b6(param_1,puVar1);
    break;
  case 0x30:
    func_0x0045257a(param_1,puVar1);
    break;
  case 0x31:
    FUN_00452199(param_1,puVar1);
    break;
  case 0x32:
    FUN_0044cc47(param_1,puVar1);
    break;
  case 0x33:
    FUN_00455338(param_1,puVar1);
  }
  return;
}

